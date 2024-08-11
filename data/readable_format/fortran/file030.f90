module regrid_module
  implicit none
contains
  subroutine integer_regrid_3d_r8(data_in, landmask_in, regrid_factor, im_o, jm_o, &
       ntim, jm_i, im_i, data_out, landmask_out)
    real, intent(in) :: data_in(ntim, jm_i, im_i)
    logical, intent(in) :: landmask_in(jm_i, im_i)
    integer, intent(in) :: regrid_factor, ntim, jm_i, im_i
    integer, intent(in) :: jm_o, im_o
    real, intent(out) :: data_out(ntim, jm_o, im_o)
    logical, intent(out) :: landmask_out(jm_o, im_o)
    integer :: i, j, ii, jj, iii, jjj
    real :: tempsum(ntim), ngood
    real :: zero = 0.
    real :: one = 1.
    real :: eps = 0.1
    do i = 1, im_o
       do j = 1, jm_o
          tempsum(:) = zero
          ngood = zero
          do ii = 1, regrid_factor
             do jj = 1, regrid_factor
                iii = (i-1) * regrid_factor + ii
                jjj = (j-1) * regrid_factor + jj
                if ( landmask_in(jjj,iii) ) then
                   tempsum(:) = tempsum(:) + data_in(:,jjj,iii)
                   ngood = ngood + one
                endif
             end do
          end do
          if ( ngood > eps) then
             data_out(:,j,i) = tempsum(:) / ngood
             landmask_out(j,i) = .true.
          else
             landmask_out(j,i) = .false.
          endif
       end do
    end do
  end subroutine integer_regrid_3d_r8
end module regrid_module

program test_regrid
  use regrid_module
  implicit none
  real, allocatable :: data_in(:,:,:), data_out(:,:,:)
  logical, allocatable :: landmask_in(:,:), landmask_out(:,:)
  integer :: regrid_factor, im_o, jm_o, ntim, jm_i, im_i, i, j, t

  ! Define test case parameters
  regrid_factor = 2
  ntim = 1
  jm_i = 4
  im_i = 4
  jm_o = 2
  im_o = 2

  allocate(data_in(ntim, jm_i, im_i))
  allocate(data_out(ntim, jm_o, im_o))
  allocate(landmask_in(jm_i, im_i))
  allocate(landmask_out(jm_o, im_o))

  ! Initialize input data and landmask
  data_in = reshape([(/ (i, i=1, jm_i*im_i*ntim) /)], shape(data_in))
  landmask_in = reshape([.true., .true., .false., .false., &
                         .true., .true., .false., .false., &
                         .false., .false., .true., .true., &
                         .false., .false., .true., .true.], shape(landmask_in))

  ! Call the subroutine
  call integer_regrid_3d_r8(data_in, landmask_in, regrid_factor, im_o, jm_o, &
       ntim, jm_i, im_i, data_out, landmask_out)

  ! Print output for verification
  print *, 'Data Out:'
  do t = 1, ntim
    do j = 1, jm_o
      print *, data_out(t, j, :)
    end do
  end do

  print *, 'Landmask Out:'
  do j = 1, jm_o
    print *, landmask_out(j, :)
  end do

  ! Deallocate arrays
  deallocate(data_in, data_out, landmask_in, landmask_out)
end program test_regrid