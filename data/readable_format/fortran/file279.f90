module foo
  implicit none
  type :: t
     integer :: i
  end type t
  interface operator (*)
     module procedure mult
  end interface
contains
  function mult (i, j)
    type(t), intent(in) :: i, j
    integer             :: mult
    mult = i%i * j%i
  end function mult

  ! Test subroutine for foo
  subroutine testFoo
    type(t) :: i = t(2), j = t(3)
    if (i*j == 6) then
      print *, 'Foo Test Passed'
    else
      print *, 'Foo Test Failed'
    end if
  end subroutine testFoo
end module foo

module bar
  implicit none
  type :: t2
     integer :: i
  end type t2
  interface operator (>)
     module procedure gt
  end interface
contains
  function gt (i, j)
    type(t2), intent(in) :: i, j
    logical               :: gt
    gt = i%i > j%i
  end function gt

  ! Test subroutine for bar
  subroutine testBar
    type(t2) :: k = t2(4), l = t2(5)
    if (.not. (k > l) .and. (l > k)) then
      print *, 'Bar Test Passed'
    else
      print *, 'Bar Test Failed'
    end if
  end subroutine testBar
end module bar

program testDriver
  use foo
  use bar
  implicit none
  type(t) :: i = t(1), j = t(2)
  type(t2) :: k = t2(1), l = t2(2)

  ! Running functionality tests
  print *, 'i*j = ', i*j
  print *, 'k > l = ', k > l

  ! Running unit tests
  call testFoo
  call testBar
end program testDriver