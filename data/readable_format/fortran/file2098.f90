! Combined Fortran code with module and test program
module fortium_defines
    use iso_c_binding
    implicit none

    integer(c_int64_t), parameter :: crypto_hash_sha512_BYTES = 64
    integer(c_int64_t), parameter :: crypto_auth_hmacsha512_BYTES = 64
    integer(c_int64_t), parameter :: crypto_auth_hmacsha512_KEYBYTES = 64
    character(len=*), parameter :: crypto_auth_PRIMITIVE = 'hmacsha512256'
    integer(c_int64_t), parameter :: crypto_auth_hmacsha512256_BYTES = 32
    integer(c_int64_t), parameter :: crypto_auth_hmacsha512256_KEYBYTES = 32
    integer(c_int64_t), parameter :: crypto_auth_BYTES = crypto_auth_hmacsha512256_BYTES
    integer(c_int64_t), parameter :: crypto_auth_KEYBYTES = crypto_auth_hmacsha512256_KEYBYTES
end module fortium_defines

program test_fortium_defines
    use fortium_defines
    implicit none

    print *, "Testing Fortran constants..."
    print *, "crypto_hash_sha512_BYTES =", crypto_hash_sha512_BYTES
    print *, "crypto_auth_hmacsha512_BYTES =", crypto_auth_hmacsha512_BYTES
    print *, "crypto_auth_hmacsha512_KEYBYTES =", crypto_auth_hmacsha512_KEYBYTES
    print *, "crypto_auth_PRIMITIVE =", trim(crypto_auth_PRIMITIVE)
    print *, "crypto_auth_hmacsha512256_BYTES =", crypto_auth_hmacsha512256_BYTES
    print *, "crypto_auth_hmacsha512256_KEYBYTES =", crypto_auth_hmacsha512256_KEYBYTES
    print *, "crypto_auth_BYTES =", crypto_auth_BYTES
    print *, "crypto_auth_KEYBYTES =", crypto_auth_KEYBYTES
end program test_fortium_defines