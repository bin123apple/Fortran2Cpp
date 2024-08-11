program mifu_run
    implicit none
    integer :: test_count

    ! Initialize test count
    test_count = 0

    ! Register tests
    call register_test("test_dummyABFail")
    call register_test("test_dummyABPass")

    ! Run registered tests
    call run_tests()

contains

    subroutine register_test(test_name)
        character(len=*), intent(in) :: test_name
        test_count = test_count + 1
        print *, "Registering test:", trim(test_name)
        ! Here, you'd typically store the test name and associate it with a test function
    end subroutine register_test

    subroutine run_tests()
        print *, "Running all registered tests..."
        call test_dummyABFail()
        call test_dummyABPass()
    end subroutine run_tests

    subroutine test_dummyABFail()
        print *, "Running test_dummyABFail..."
        ! Implement the test logic here
    end subroutine test_dummyABFail

    subroutine test_dummyABPass()
        print *, "Running test_dummyABPass..."
        ! Implement the test logic here
    end subroutine test_dummyABPass

end program mifu_run