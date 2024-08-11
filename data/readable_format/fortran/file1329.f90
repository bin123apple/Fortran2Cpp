program main
    use iso_fortran_env, only: int64
    implicit none
    integer(int64) :: i, MIN_RES = 1020304050607080900_int64
    logical :: result

    i = floor(sqrt(real(MIN_RES)))

    do while (.TRUE.)
        if (concealed_sqr(i*i)) then
            exit
        endif
        i = i + 1
    end do

    print *, "The number is: ", i

contains

    pure function concealed_sqr(tmp) result(is_concealed)
        integer(int64), intent(in) :: tmp
        integer(int64) :: a, i
        logical :: is_concealed
        is_concealed = mod(tmp, 10) == 0
        i = tmp / 100
        a = 9
        do while (i > 0 .and. is_concealed)
            is_concealed = mod(i, 10) == a
            i = i / 100
            a = a - 1
        end do
    end function concealed_sqr

end program main