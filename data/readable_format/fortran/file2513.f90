program test_init_company
    implicit none

    ! Assuming the sizes
    integer, parameter :: max_company = 10
    integer, parameter :: lcompany_entry = 5
    integer, parameter :: c_company_id = 1  ! Adjusted for Fortran indexing (Fortran starts at 1)
    integer :: i, j

    ! Assuming the tables
    integer :: c_table(max_company, lcompany_entry)
    character(len=1) :: company_sial_prog(max_company)

    ! Initialize the company data
    call init_company

    ! Print the tables to verify the initialization
    do i = 1, max_company
        do j = 1, lcompany_entry
            write(*, '(I3)', advance='no') c_table(i, j)
        end do
        write(*, '(A)', advance='no') ' | '
        write(*, '(A)') company_sial_prog(i)
    end do

contains

    subroutine init_company
        integer :: i, j

        ! Initialize the company data
        do i = 1, max_company
            do j = 1, lcompany_entry
                c_table(i, j) = 0
            end do
            ! Use a placeholder for MPI_UNDEFINED since MPI is not being used
            c_table(i, c_company_id) = -1
            company_sial_prog(i) = ' '
        end do
    end subroutine init_company

end program test_init_company