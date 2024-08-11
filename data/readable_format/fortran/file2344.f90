program testproduct
    implicit none
    integer, dimension(3, 3) :: a
    integer, dimension(3) :: b
    logical, dimension(3, 3) :: m
    integer :: total_prod

    ! Initialize matrix 'a'
    a = reshape((/1, 2, 3, 4, 5, 6, 7, 8, 9/), (/3, 3/))

    ! Test product along the first dimension
    b = product(a, 1)
    if (any(b /= (/6, 120, 504/))) then
        print *, "Test failed: Product along dimension 1"
        call abort
    endif

    ! Test total product
    total_prod = product(a)
    if (total_prod /= 362880) then
        print *, "Test failed: Total product"
        call abort
    endif

    ! Initialize mask 'm'
    m = .true.
    m(1, 1) = .false.
    m(2, 1) = .false.

    ! Test product along the second dimension with mask
    b = product(a, 2, m)
    if (any(b /= (/28, 40, 162/))) then
        print *, "Test failed: Product along dimension 2 with mask"
        call abort
    endif

    ! Test total product with mask
    total_prod = product(a, mask=m)
    if (total_prod /= 181440) then
        print *, "Test failed: Total product with mask"
        call abort
    endif

    print *, "All tests passed successfully."
end program testproduct