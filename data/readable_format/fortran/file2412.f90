program test_graphic_copy_line_opt
    implicit none

    integer, parameter :: len_line_opt = 100
    integer :: line_style_from(len_line_opt)
    integer :: line_style_to(len_line_opt)
    integer :: s
    integer :: i
    logical :: test_passed

    ! Initialize test data
    s = 0
    do i = 1, len_line_opt
        line_style_from(i) = i
        line_style_to(i) = 0
    end do

    ! Call the subroutine
    call graphic_copy_line_opt(line_style_from, line_style_to, s)

    ! Verify the result
    test_passed = .true.
    do i = 1, len_line_opt
        if (line_style_to(i) /= line_style_from(i)) then
            test_passed = .false.
            print *, 'Test failed at index ', i
            exit
        end if
    end do

    if (test_passed) then
        print *, 'Test passed'
    else
        print *, 'Test failed'
    end if

contains

    subroutine graphic_copy_line_opt(line_style_from, line_style_to, s)
        integer, intent(in) :: line_style_from(len_line_opt)
        integer, intent(out) :: line_style_to(len_line_opt)
        integer, intent(in) :: s
        integer :: l

        if (s /= 0) return
        do l = 1, len_line_opt
            line_style_to(l) = line_style_from(l)
        end do
    end subroutine graphic_copy_line_opt

end program test_graphic_copy_line_opt