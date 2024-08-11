program test_clawpack46_tag4refinement
  implicit none

  integer :: mx, my, mbc, meqn, blockno, tag_for_refinement, init_flag
  double precision :: xlower, ylower, dx, dy, refine_threshold
  double precision, dimension(:,:,:), allocatable :: q

  ! Initialize test parameters
  mx = 4
  my = 4
  mbc = 1
  meqn = 1
  xlower = 0.0
  ylower = 0.0
  dx = 1.0
  dy = 1.0
  blockno = 1
  refine_threshold = 0.5
  init_flag = 1

  allocate(q(1-mbc:mx+mbc, 1-mbc:my+mbc, meqn))

  ! Initialize q with some test values
  q = 0.0
  q(3, 3, 1) = 1.0  ! Set a value that should trigger refinement

  ! Call the subroutine
  call clawpack46_tag4refinement(mx, my, mbc, meqn, xlower, ylower, &
     dx, dy, blockno, q, refine_threshold, init_flag, tag_for_refinement)

  ! Print the result
  print *, 'Tag for refinement:', tag_for_refinement

  deallocate(q)

end program test_clawpack46_tag4refinement

subroutine clawpack46_tag4refinement(mx, my, mbc, meqn, xlower, ylower, &
     dx, dy, blockno, q, refine_threshold, init_flag, tag_for_refinement)
  implicit none

  integer mx, my, mbc, meqn, tag_for_refinement, init_flag
  integer blockno
  double precision xlower, ylower, dx, dy
  double precision refine_threshold
  double precision q(1-mbc:mx+mbc, 1-mbc:my+mbc, meqn)

  integer i, j, mq
  double precision qx, qy

  tag_for_refinement = 0

  do mq = 1, meqn
    do i = 1, mx
      do j = 1, my
        qx = (q(i+1, j, 1) - q(i-1, j, 1)) / (2*dx)
        qy = (q(i, j+1, 1) - q(i, j-1, 1)) / (2*dy)
        if (abs(qx) .gt. refine_threshold .or. abs(qy) .gt. refine_threshold) then
          tag_for_refinement = 1
          return
        endif
      enddo
    enddo
  enddo

end subroutine clawpack46_tag4refinement