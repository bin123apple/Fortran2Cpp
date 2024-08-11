program test
    implicit none

    type t
        logical :: valid
        integer :: x, y
    end type t

    type(t), dimension(5) :: s
    type(t), dimension(5) :: d
    integer :: i

    ! Initialize array 's'
    do i = 1, 5
        s(i)%valid = .true.
        s(i)%x = i
        s(i)%y = i * 10
    end do

    ! Copy 's' to 'd'
    d = s

    ! Test to check if 's' and 'd' match
    do i = 1, 5
        if (s(i)%valid .neqv. d(i)%valid .or. s(i)%x /= d(i)%x .or. s(i)%y /= d(i)%y) then
            print *, "Test failed at index", i
            stop
        end if
    end do

    print *, "All tests passed successfully."

end program test