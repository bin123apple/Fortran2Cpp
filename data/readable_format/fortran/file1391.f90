module check_arrays_module
    implicit none
contains
    subroutine check_arrays(auxiliary_empty_cells, current_empty_cells, empty_cells, error_index)
        integer(4), intent(in) :: auxiliary_empty_cells(0:255)
        integer(4), intent(in) :: current_empty_cells
        integer(4), intent(in) :: empty_cells(0:255)
        integer(4), intent(out) :: error_index
        integer(4) :: i

        error_index = -1
        do i=0,current_empty_cells-1
            if (i /= auxiliary_empty_cells(empty_cells(i))) then
                error_index = empty_cells(i)
                return
            end if
        end do
    end subroutine check_arrays
end module check_arrays_module

program test_check_arrays
    use check_arrays_module
    implicit none
    integer(4) :: auxiliary_empty_cells(0:255)
    integer(4) :: current_empty_cells
    integer(4) :: empty_cells(0:255)
    integer(4) :: error_index
    integer(4) :: i

    ! Initialize arrays
    do i = 0, 255
        auxiliary_empty_cells(i) = i
        empty_cells(i) = i
    end do

    current_empty_cells = 5

    call check_arrays(auxiliary_empty_cells, current_empty_cells, empty_cells, error_index)

    if (error_index == -1) then
        print *, "Test passed."
    else
        print *, "Test failed. Error index:", error_index
    end if
end program test_check_arrays