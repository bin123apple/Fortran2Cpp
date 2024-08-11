module hashing
  use, intrinsic :: iso_c_binding
  implicit none

contains

  function MurmurHash2(key, N, seed) result(hash) bind(C, name='MurmurHash2')
    ! Mock-up function signature. In a real scenario, this would be an external C function.
    integer(c_int32_t) :: hash
    type(c_ptr), value :: key
    integer(c_int), value :: N
    integer(c_int32_t), value :: seed
    ! Mock hash computation (very simple and not a real hash function)
    hash = seed + N
  end function MurmurHash2

  function murmurhash_bit_string(f, N, seed) result(hash)
    integer :: hash
    integer, intent(in) :: N
    integer, intent(in), target :: f(N)
    integer(c_int32_t), intent(in) :: seed
    type(c_ptr) :: key
    integer(c_int) :: nbytes

    nbytes = ceiling(real(N)/32)*4
    key = c_loc(f(1))

    hash = MurmurHash2(key, nbytes, seed)
  end function murmurhash_bit_string

end module hashing

program test_hashing
  use hashing
  implicit none

  integer :: test_array(8) = [1, 0, 0, 0, 0, 0, 0, 0]
  integer :: result
  integer, parameter :: seed = 42

  result = murmurhash_bit_string(test_array, size(test_array), seed)
  print *, "Result:", result
end program test_hashing