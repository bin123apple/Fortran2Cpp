program testSHConfidence
    implicit none
    real*8 :: result
    integer :: test_case
    real*8, parameter :: test_values(3) = [0.1d0, 0.5d0, 0.9d0]
    integer, parameter :: l_conf_values(3) = [2, 5, 10]

    do test_case = 1, 3
        result = SHConfidence(l_conf_values(test_case), test_values(test_case))
        print *, "l_conf =", l_conf_values(test_case), "r =", test_values(test_case), "Result =", result
    end do

contains

    real*8 function SHConfidence(l_conf, r)
        implicit none
        real*8, intent(in) :: r
        integer, intent(in) :: l_conf
        real*8 :: prod
        integer :: l, i

        SHConfidence = abs(r)
        prod = 1.0d0
        
        do l = 2, l_conf, 1
            i = l-1
            prod = prod * dble(2*i-1) / dble(2*i)
            SHConfidence = SHConfidence + prod * abs(r) * (1.0d0 - r**2)**(l-1)
        end do
    end function SHConfidence

end program testSHConfidence