program pr42866_test
  implicit none
  integer, allocatable :: a(:)
  
  call test_parallel_sections()
  
contains

  subroutine test_parallel_sections()
    allocate(a(16))
    a = 0
    !$omp parallel
      !$omp sections reduction(+:a)
        a = a + 1
      !$omp section
        a = a + 2
      !$omp end sections
    !$omp end parallel
    if (all(a == 3)) then
      print *, "Test Passed: All elements are 3."
    else
      print *, "Test Failed: Not all elements are 3."
    endif
    deallocate(a)
  end subroutine test_parallel_sections

end program pr42866_test