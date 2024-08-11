module great_module
contains
    subroutine great(arg1, arg2)
        implicit none
        character(len=*), intent(in) :: arg1, arg2
        print *, trim(arg1), "and", trim(arg2), "are in 'great' subroutine."
    end subroutine great
end module great_module

program test_great_program
    use great_module
    implicit none

    call test_great_behavior()

contains

    subroutine test_great_behavior()
        call great('test1', 'test2')
        call great('data1', 'data2')
        print *, 'Test cases for "great" executed. Please verify output manually.'
    end subroutine test_great_behavior

end program test_great_program