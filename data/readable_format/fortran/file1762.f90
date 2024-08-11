program t
  implicit none
  integer::k=-1
  call test_s()
contains

  subroutine s(j,k)
    integer,intent(in)::j
    integer,intent(out)::k
    integer::i=1
    print '(i0)',i+j
    k=77
  end subroutine s

  subroutine test_s()
    integer::expected_sum, expected_k, j, k
    j = 2
    k = -1
    expected_sum = 3
    expected_k = 77

    print *, 'Testing subroutine s with j=2...'
    call s(j, k)
    if (k == expected_k) then
      print *, 'PASS: k correctly updated to 77.'
    else
      print *, 'FAIL: k not correctly updated.'
    endif
  end subroutine test_s

end program t