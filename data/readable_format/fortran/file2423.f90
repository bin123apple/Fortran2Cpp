! Define the subroutine
subroutine fc3d_clawpack5_fort_tag4refinement(mx, my, mz, mbc, &
       meqn, xlower, ylower, zlower, dx, dy, dz, blockno, &
       q, tag_threshold, init_flag, tag_patch)
  implicit none

  integer :: mx, my, mz, mbc, meqn, blockno, tag_patch, init_flag
  double precision :: xlower, ylower, zlower, dx, dy, dz, tag_threshold
  double precision, dimension(meqn,1-mbc:mx+mbc,1-mbc:my+mbc,1-mbc:mz+mbc) :: q

  integer :: i, j, k, mq
  double precision :: qmin, qmax

  tag_patch = 0
  mq = 1
  qmin = q(mq,1,1,1)
  qmax = q(mq,1,1,1)
  do k = 1-mbc, mz+mbc
     do j = 1-mbc, my+mbc
        do i = 1-mbc, mx+mbc
           qmin = min(q(mq,i,j,k), qmin)
           qmax = max(q(mq,i,j,k), qmax)
           if (qmax - qmin > tag_threshold) then
              tag_patch = 1
              return
           endif
        end do
     end do
  end do
end subroutine fc3d_clawpack5_fort_tag4refinement

! Main program to test the subroutine
program test_fc3d_clawpack5
  implicit none
  integer :: mx, my, mz, mbc, meqn, blockno, tag_patch, init_flag
  double precision :: xlower, ylower, zlower, dx, dy, dz, tag_threshold
  double precision, allocatable :: q(:,:,:,:)

  ! Initialize parameters
  mx = 4
  my = 4
  mz = 4
  mbc = 1
  meqn = 1
  blockno = 0
  xlower = 0.0
  ylower = 0.0
  zlower = 0.0
  dx = 1.0
  dy = 1.0
  dz = 1.0
  tag_threshold = 0.5
  init_flag = 0

  ! Allocate and initialize array q
  allocate(q(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc, 1-mbc:mz+mbc))
  q = 0.0
  q(1, 2, 2, 2) = 1.0  ! Set a value that will trigger the tag

  ! Call the subroutine
  call fc3d_clawpack5_fort_tag4refinement(mx, my, mz, mbc, meqn, xlower, &
       ylower, zlower, dx, dy, dz, blockno, q, tag_threshold, init_flag, tag_patch)

  ! Print the result
  print *, 'Tag Patch:', tag_patch

  ! Clean up
  deallocate(q)
end program test_fc3d_clawpack5