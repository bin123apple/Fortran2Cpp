program test_translation
    logical, volatile :: t1
    logical :: t2
    integer :: i

    t2 = .false.
    t1 = .false.
    do i = 1, 2
        if (t1) print *, 'VolatileNotOptimizedAway'
        if (t2) print *, 'NonVolatileNotOptimizedAway'
    end do
end program test_translation