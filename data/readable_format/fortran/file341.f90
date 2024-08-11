module random_ic_mod
    implicit none
contains
    function generate_random() result(r)
        real :: r
        call random_seed()
        call random_number(r)
    end function generate_random
end module random_ic_mod

program test_random_ic
    use random_ic_mod
    implicit none
    real :: random_value

    random_value = generate_random()
    print *, "Generated random value: ", random_value
end program test_random_ic