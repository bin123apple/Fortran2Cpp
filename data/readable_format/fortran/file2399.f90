program test_enq_v1_iae_code
    implicit none

    integer :: n, iae, s

    ! Test case 1: s equals 0, expect iae to be set to n
    n = 5
    iae = 0
    s = 0
    call enq_v1_iae_code(n, iae, s)
    if (iae /= n) then
        print *, 'Test 1 failed: Expected iae = ', n, ' but got ', iae
    else
        print *, 'Test 1 passed: iae = ', iae
    endif

    ! Test case 2: s not equals 0, expect iae to remain unchanged
    n = 10
    iae = 0
    s = 1
    call enq_v1_iae_code(n, iae, s)
    if (iae /= 0) then
        print *, 'Test 2 failed: Expected iae = 0 but got ', iae
    else
        print *, 'Test 2 passed: iae = ', iae
    endif

contains

    ! Mock subroutine (to replace the actual enq_v1_iae_code for testing)
    subroutine enq_v1_iae_code(n, iae, s)
        integer, intent(in) :: n, s
        integer, intent(inout) :: iae

        if (s /= 0) return

        iae = n
    end subroutine enq_v1_iae_code

end program test_enq_v1_iae_code