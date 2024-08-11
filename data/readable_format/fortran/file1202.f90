program p
  implicit none

  type :: t1
    integer :: c1
  end type t1

  type :: t2
    type(t1), allocatable :: c2
  end type t2

  call test_program()

contains

  subroutine test_program()
    type(t2) :: v(4)
    integer :: i

    v = t2(t1(3))
    v(2)%c2%c1 = 7
    v(3)%c2%c1 = 11
    v(4)%c2%c1 = 13

    do i = 1, 4
      select case (i)
      case (1)
        if (v(i)%c2%c1 /= 3) then
          print *, 'Test failed for v(1)'
          stop 1
        end if
      case (2)
        if (v(i)%c2%c1 /= 7) then
          print *, 'Test failed for v(2)'
          stop 2
        end if
      case (3)
        if (v(i)%c2%c1 /= 11) then
          print *, 'Test failed for v(3)'
          stop 3
        end if
      case (4)
        if (v(i)%c2%c1 /= 13) then
          print *, 'Test failed for v(4)'
          stop 4
        end if
      end select
    end do

    print *, 'All tests passed!'
  end subroutine test_program

end program p