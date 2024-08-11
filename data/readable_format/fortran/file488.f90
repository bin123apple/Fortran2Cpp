program test_lookup_shell
  implicit none
  integer, allocatable :: table(:)
  integer :: m

  ! Test 1: Empty input table
  allocate(table(0))
  call lookup_shell(table, 0, 3, m)
  print *, "Test 1 (Empty table), Expected: 0, Got:", m
  deallocate(table)

  ! Test 2: Table with elements all smaller than `a`
  allocate(table(3))
  table = (/1, 2, 3/)
  call lookup_shell(table, 3, 4, m)
  print *, "Test 2 (All smaller), Expected: 3, Got:", m
  deallocate(table)

  ! Test 3: Table with elements all greater than or equal to `a`
  allocate(table(3))
  table = (/4, 5, 6/)
  call lookup_shell(table, 3, 2, m)
  print *, "Test 3 (All greater or equal), Expected: 1, Got:", m
  deallocate(table)

  ! Test 4: Table with some elements smaller and some greater, `a` not present
  allocate(table(5))
  table = (/1, 3, 5, 7, 9/)
  call lookup_shell(table, 5, 6, m)
  print *, "Test 4 (Mixed, a not present), Expected: 4, Got:", m
  deallocate(table)

  ! Test 5: Table with some elements smaller and some greater, `a` present
  allocate(table(5))
  table = (/1, 3, 5, 7, 9/)
  call lookup_shell(table, 5, 5, m)
  print *, "Test 5 (Mixed, a present), Expected: 3, Got:", m
  deallocate(table)

  ! Test 6: Table where the first element is greater than or equal to `a`
  allocate(table(3))
  table = (/2, 3, 4/)
  call lookup_shell(table, 3, 2, m)
  print *, "Test 6 (First element >= a), Expected: 1, Got:", m
  deallocate(table)

  ! Test 7: Table where the last element is the first that is greater than or equal to `a`
  allocate(table(4))
  table = (/1, 2, 3, 4/)
  call lookup_shell(table, 4, 4, m)
  print *, "Test 7 (Last element first >= a), Expected: 4, Got:", m
  deallocate(table)

end program test_lookup_shell

subroutine lookup_shell(table, nshells, a, m)
  implicit none
  integer nshells
  integer table(nshells)
  integer i, a, m

  m = 0
  do i = 1, nshells
     if (table(i) .ge. a) then
        m = i
        return
     endif
  enddo

  m = nshells
  return
end