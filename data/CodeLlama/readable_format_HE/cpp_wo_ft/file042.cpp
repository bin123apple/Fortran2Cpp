[INST] Translate this Fortran code to C++: 
program encode_decode_vigenere
    implicit none
    integer :: i, j, l
    character(len=21) :: str, encoded_str, decoded_str
    character(len=1) :: chr
    real :: rand_val

    call random_seed()

    do i = 1, 100
        call random_number(rand_val)
        l = 10 + int(rand_val * 11)
        str = ""
        do j = 1, l
            call random_number(rand_val)
            chr = char(97 + int(rand_val * 26))
            str(j:j) = chr
        end do

        encoded_str = encode_vigenere(trim(str))
        decoded_str = decode_vigenere(trim(encoded_str))

        if (trim(decoded_str) /= trim(str)) then
            write(*,*) "Assertion failed: decoded string does not match original"
            stop 1
        end if
    end do
contains
    function encode_vigenere(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 5 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function encode_vigenere

    function decode_vigenere(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 21 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function decode_vigenere
end program encode_decode_vigenere [/INST]

[INST] Translate this Fortran code to C++: 
program encode_decode_caesar
    implicit none
    integer :: i, j, l
    character(len=21) :: str, encoded_str, decoded_str
    character(len=1) :: chr
    real :: rand_val

    call random_seed()

    do i = 1, 100
        call random_number(rand_val)
        l = 10 + int(rand_val * 11)
        str = ""
        do j = 1, l
            call random_number(rand_val)
            chr = char(97 + int(rand_val * 26))
            str(j:j) = chr
        end do

        encoded_str = encode_caesar(trim(str))
        decoded_str = decode_caesar(trim(encoded_str))

        if (trim(decoded_str) /= trim(str)) then
            write(*,*) "Assertion failed: decoded string does not match original"
            stop 1
        end if
    end do
contains
    function encode_caesar(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 5 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function encode_caesar

    function decode_caesar(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 21 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function decode_caesar
end program encode_decode_caesar [/INST]

[INST] Translate this Fortran code to C++: 
program encode_decode_atbash
    implicit none
    integer :: i, j, l
    character(len=21) :: str, encoded_str, decoded_str
    character(len=1) :: chr
    real :: rand_val

    call random_seed()

    do i = 1, 100
        call random_number(rand_val)
        l = 10 + int(rand_val * 11)
        str = ""
        do j = 1, l
            call random_number(rand_val)
            chr = char(97 + int(rand_val * 26))
            str(j:j) = chr
        end do

        encoded_str = encode_atbash(trim(str))
        decoded_str = decode_atbash(trim(encoded_str))

        if (trim(decoded_str) /= trim(str)) then
            write(*,*) "Assertion failed: decoded string does not match original"
            stop 1
        end if
    end do
contains
    function encode_atbash(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 5 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function encode_atbash

    function decode_atbash(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 21 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function decode_atbash
end program encode_decode_atbash [/INST]

[INST] Translate this Fortran code to C++: 
program encode_decode_rot13
    implicit none
    integer :: i, j, l
    character(len=21) :: str, encoded_str, decoded_str
    character(len=1) :: chr
    real :: rand_val

    call random_seed()

    do i = 1, 100
        call random_number(rand_val)
        l = 10 + int(rand_val * 11)
        str = ""
        do j = 1, l
            call random_number(rand_val)
            chr = char(97 + int(rand_val * 26))
            str(j:j) = chr
        end do

        encoded_str = encode_rot13(trim(str))
        decoded_str = decode_rot13(trim(encoded_str))

        if (trim(decoded_str) /= trim(str)) then
            write(*,*) "Assertion failed: decoded string does not match original"
            stop 1
        end if
    end do
contains
    function encode_rot13(s) result(out)
        character(len=*), intent(in) :: s
        character(len=len(s)) :: out
        integer :: i, w

        out = s
        do i = 1, len(s)
            w = mod(iachar(s(i:i)) + 5 - iachar('a'), 26) + iachar('a')
            out(i:i) = char(w)
        end do
    end function encode_rot13

    function decode_rot13(s) result(out)
        character(len=*), intent(in) :: s
