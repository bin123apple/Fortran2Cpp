program test
  implicit none
  character(*), parameter :: n = ''
  character(*), parameter :: o = transfer ([''], n)
  character(*), parameter :: p = transfer ( n , n)
  character(*), parameter :: q = transfer ([n], n)
  character(6), save      :: r = transfer ([''], n)
  character(6), save      :: s = transfer ( n , n)
  character(6), save      :: t = transfer ([n], n)
  integer,      parameter :: a(0) = 0
  integer,      parameter :: b(0) = transfer (a, a)
  integer,      save      :: c(0) = transfer (a, a)

  ! Basic check functions
  call checkLength('o', len(o), 0)
  call checkLength('p', len(p), 0)
  call checkLength('q', len(q), 0)
  call checkString('r', r, "")
  call checkString('s', s, "")
  call checkString('t', t, "")
  call checkArray('b', b, 0)
  call checkArray('c', c, 0)

contains

  subroutine checkLength(name, value, expected)
    character(*), intent(in) :: name
    integer, intent(in) :: value, expected
    if (value /= expected) then
      print *, "Length check failed for ", name, ": ", value, " /= ", expected
    else
      print *, "Length check passed for ", name
    endif
  end subroutine checkLength

  subroutine checkString(name, value, expected)
    character(*), intent(in) :: name, value, expected
    if (value /= expected) then
      print *, "String check failed for ", name, ": ", value, " /= ", expected
    else
      print *, "String check passed for ", name
    endif
  end subroutine checkString

  subroutine checkArray(name, array, expectedSize)
    character(*), intent(in) :: name
    integer, intent(in) :: array(:), expectedSize
    if (size(array) /= expectedSize) then
      print *, "Array size check failed for ", name, ": size ", size(array), " /= ", expectedSize
    else
      print *, "Array size check passed for ", name
    endif
  end subroutine checkArray

end program test