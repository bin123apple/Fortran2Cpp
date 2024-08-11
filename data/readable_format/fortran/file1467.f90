program test_reshape

  implicit none
  integer, allocatable :: vect1(:), resh1(:,:)
  integer, pointer :: vect(:), resh(:,:)
  integer :: vect2(2*4), resh2(2,4)
  integer :: r, nb
  logical :: test_passed

  r = 2
  nb = 4

  allocate(vect(nb*r),vect1(nb*r))
  allocate(resh(r,nb),resh1(r,nb))

  vect = 1
  vect1 = 1
  vect2 = 1

  resh2 = reshape(vect2, (/r,nb/))
  test_passed = all(resh2 == 1)
  call assert(test_passed, 1)

  resh1 = reshape(vect1, (/r,nb/))
  test_passed = all(resh1 == 1)
  call assert(test_passed, 2)

  resh = reshape(vect, (/r,nb/))
  test_passed = all(resh == 1)
  call assert(test_passed, 3)

contains

  subroutine assert(condition, error_code)
    logical, intent(in) :: condition
    integer, intent(in) :: error_code
    if (.not. condition) then
      write(*,*) 'Test failed with error code:', error_code
      stop
    endif
  end subroutine assert

end program test_reshape