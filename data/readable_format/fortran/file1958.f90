module automatic_deallocation

  implicit none
  private
  public :: t0, t1, t2, a, b, c, d

  type t0
    integer :: i
  end type t0

  type t1
    real :: pi = 3.14
    integer, allocatable :: j
  end type t1

  type t2
    class(t0), allocatable :: k
  end type t2

contains

  subroutine a
    integer, allocatable :: m
    allocate (m)
    m = 42
    ! Normally, we would return or modify a global to check this
    print *, "Subroutine a: m allocated and set to", m
    deallocate(m)
  end subroutine a

  subroutine b
    class(t0), allocatable :: m
    allocate (t0 :: m)
    m%i = 43
    print *, "Subroutine b: m%i allocated and set to", m%i
    deallocate(m)
  end subroutine b

  subroutine c
    type(t1) :: m
    allocate (m%j)
    m%j = 44
    print *, "Subroutine c: m%j allocated and set to", m%j
    deallocate(m%j)
  end subroutine c

  subroutine d
    type(t2) :: m
    allocate (t0 :: m%k)
    m%k%i = 45
    print *, "Subroutine d: m%k%i allocated and set to", m%k%i
    deallocate(m%k)
  end subroutine d

end module automatic_deallocation

program test_automatic_deallocation
    use automatic_deallocation
    implicit none

    call a
    call b
    call c
    call d

    print *, "All subroutines tested."
end program test_automatic_deallocation