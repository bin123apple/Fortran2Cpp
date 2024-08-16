[/FOLD]

[FOLD=Fortran 2003]

[INST] Translate this Fortran code to C++: 
program nested_parens
    implicit none
    character(len=100) :: paren_string
    integer, dimension(:), allocatable :: result
    integer, dimension(4) :: expected1 = [2, 3, 1, 3]
    integer, dimension(4) :: expected2 = [1, 2, 3, 4]
    integer, dimension(1) :: expected3 = [4]
    logical :: is_same

    paren_string = '(()()) ((())) () ((())()())'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected1)
    if (.not. is_same) then
        write(*,*) "Assertion failed for test case 1"
        call exit(1)
    end if

    paren_string = '() (()) ((())) (((())))'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected2)
    if (.not. is_same) then
        write(*,*) "Assertion failed for test case 2"
        call exit(1)
    end if

    paren_string = '(()(())((())))'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected3)
    if (.not. is_same) then
        write(*,*) "Assertion failed for test case 3"
        call exit(1)
    end if

contains

    subroutine parse_nested_parens(paren_string, all_levels)
        character(len=*), intent(in) :: paren_string
        integer, dimension(:), allocatable, intent(out) :: all_levels
        integer :: level, max_level, i, n
        character(len=1) :: chr
        integer, dimension(:), allocatable :: temp_levels

        level = 0
        max_level = 0
        n = len_trim(paren_string)
        allocate(temp_levels(n))
        temp_levels = 0

        do i = 1, n
            chr = paren_string(i:i)
            if (chr == '(') then
                level = level + 1
                if (level > max_level) max_level = level
            else if (chr == ')') then
                level = level - 1
                if (level == 0) then
                    temp_levels(i) = max_level
                    max_level = 0
                end if
            end if
        end do

        ! Filter out zeros and allocate the result array
        allocate(all_levels(count(temp_levels /= 0)))
        all_levels = pack(temp_levels, temp_levels /= 0)
    end subroutine parse_nested_parens

    logical function issame(a, b)
        integer, dimension(:), intent(in) :: a, b
        integer :: i

        if (size(a) /= size(b)) then
            issame = .false.
            return
        end if

        do i = 1, size(a)
            if (a(i) /= b(i)) then
                issame = .false.
                return
            end if
        end do

        issame = .true.
    end function issame

end program nested_parens [/INST]

[/FOLD]

[FOLD=Fortran 2008]

[INST] Translate this Fortran code to C++: 
program nested_parens
    implicit none
    character(len=100) :: paren_string
    integer, dimension(:), allocatable :: result
    integer, dimension(4) :: expected1 = [2, 3, 1, 3]
    integer, dimension(4) :: expected2 = [1, 2, 3, 4]
    integer, dimension(1) :: expected3 = [4]
    logical :: is_same

    paren_string = '(()()) ((())) () ((())()())'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected1)
    if (.not. is_same) then
        write(*,*) "Assertion failed for test case 1"
        call exit(1)
    end if

    paren_string = '() (()) ((())) (((())))'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected2)
    if (.not. is_same) then
        write(*,*) "Assertion failed for test case 2"
        call exit(1)
    end if

    paren_string = '(()(())((())))'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected3)
    if (.not. is_same) then
        write(*,*) "Assertion failed for test case 3"
        call exit(1)
    end if

contains

    subroutine parse_nested_parens(paren_string, all_levels)
        character(len=*), intent(in) :: paren_string
        integer, dimension(:), allocatable, intent(out) :: all_levels
        integer :: level, max_level, i, n
        character(len=1) :: chr
        integer, dimension(:), allocatable :: temp_levels

        level = 0
        max_level = 0
        n = len_trim(paren_string)
        allocate(temp_levels(n))
        temp_levels = 0

        do i = 1, n
            chr = paren_string(i:i)
            if (chr == '(') then
                level = level + 1
                if (level > max_level) max_level = level
            else if (chr == ')') then
                level = level - 1
                if (level == 0) then
                    temp_levels(i) = max_level
                    max_level = 0
                end if
            end if
        end do

        ! Filter out zeros and allocate the result array
        allocate(all_levels(count(temp_levels /= 0)))
        all_levels = pack(temp_levels, temp_levels /= 0)
    end subroutine parse_nested_parens

    logical function issame(a, b)
        integer, dimension(:), intent(in) :: a, b
        integer :: i

        if (size(a) /= size(b)) then
            issame = .false.
            return
        end if

        do i = 1, size(a)
            if (a(i) /= b(i)) then
                issame = .false.
                return
            end if
        end do

        issame = .true.
    end function issame

end program nested_parens [/INST]

[/FOLD]

[FOLD=Fortran 2018]

[INST] Translate this Fortran code to C++: 
program nested_parens
    implicit none
    character(len=100) :: paren_string
    integer, dimension(:), allocatable :: result
    integer, dimension(4) :: expected1 = [2, 3, 1, 3]
    integer, dimension(4) :: expected2 = [1, 2, 3, 4]
    integer, dimension(1) :: expected3 = [4]
    logical :: is_same

    paren_string = '(()()) ((())) () ((())()())'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected1)
    if (.not. is_same) then
        write(*,*) "Assertion failed for test case 1"
        call exit(1)
    end if

    paren_string = '() (()) ((())) (((())))'
    call parse_nested_parens(paren_string, result)
    is_same = issame(result, expected2)
    if (.not. is_same)
