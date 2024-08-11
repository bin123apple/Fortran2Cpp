module kind_values
    implicit none
    integer, parameter :: iint = selected_int_kind(8)
end module kind_values

module run_proc_0027
    use kind_values
    implicit none
contains
    subroutine run_proc_m_COads_b5(cell)
        integer(kind=iint), dimension(4), intent(inout) :: cell
        cell(4) = cell(4) + 1
    end subroutine run_proc_m_COads_b5
end module run_proc_0027

program test_run_proc
    use kind_values
    use run_proc_0027
    implicit none
    integer(kind=iint), dimension(4) :: cell

    cell = [0, 0, 0, 0]
    call run_proc_m_COads_b5(cell)
    print *, "Cell after processing:", cell
end program test_run_proc