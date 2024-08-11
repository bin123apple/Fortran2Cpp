module sum_module
    implicit none
contains
    ! Subroutine to sum elements based on a mask
    subroutine SUM_J(dv_result, dv_array, dv_dim, dv_mask)
        integer(kind=8), intent(out) :: dv_result
        integer(kind=8), intent(in) :: dv_array(:)
        integer(kind=8), intent(in) :: dv_dim
        logical, intent(in) :: dv_mask(:)
        
        integer(kind=8) :: i
        
        dv_result = 0
        do i = 1, dv_dim
            if (dv_mask(i)) then
                dv_result = dv_result + dv_array(i)
            endif
        end do
    end subroutine SUM_J
end module sum_module

program test_sum
    use sum_module
    implicit none
    
    integer(kind=8) :: result
    integer(kind=8) :: dv_dim
    integer(kind=8), dimension(5) :: array = [1, 2, 3, 4, 5]
    logical, dimension(5) :: mask = [.TRUE., .FALSE., .TRUE., .FALSE., .TRUE.]
    
    dv_dim = 5 ! Explicitly declare dv_dim as INTEGER(kind=8)
    
    call SUM_J(result, array, dv_dim, mask)
    print *, "Sum of masked elements:", result
    ! Expected output: Sum of masked elements: 9
end program test_sum