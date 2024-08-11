! Define the xxcase subroutine
subroutine xxcase(input, output, type)

    implicit none
    integer :: i
    integer :: size
    character(len=*) :: input
    character(len=*) :: output
    character(len=2) :: type

    size = len(input)
    output(1:size) = input(1:size)
    i = 1

    if (type .eq. 'UC' .or. type .eq. 'uc') then
        do while (i <= size)
            if (ichar(input(i:i)) >= ichar('a') .and. ichar(input(i:i)) <= ichar('z')) then
                output(i:i) = char(ichar(input(i:i)) - ichar('a') + ichar('A'))
            endif
            i = i + 1
        end do
    endif

    if (type .eq. 'LC' .or. type .eq. 'lc') then
        i = 1
        do while (i <= size)
            if (ichar(input(i:i)) >= ichar('A') .and. ichar(input(i:i)) <= ichar('Z')) then
                output(i:i) = char(ichar(input(i:i)) - ichar('A') + ichar('a'))
            endif
            i = i + 1
        end do
    endif

end subroutine xxcase

! Main program for testing
program testXXCase
    implicit none
    character(len=100) :: output

    ! Test 1: Convert to uppercase
    call xxcase('hello, world!', output, 'UC')
    if (output .eq. 'HELLO, WORLD!') then
        print *, 'Test 1 Passed'
    else
        print *, 'Test 1 Failed'
    endif

    ! Test 2: Convert to lowercase
    call xxcase('HELLO, WORLD!', output, 'LC')
    if (output .eq. 'hello, world!') then
        print *, 'Test 2 Passed'
    else
        print *, 'Test 2 Failed'
    endif

    ! Test 3: Mixed case input
    call xxcase('Hello, World!', output, 'uc')
    if (output .eq. 'HELLO, WORLD!') then
        print *, 'Test 3 Passed'
    else
        print *, 'Test 3 Failed'
    endif

end program testXXCase