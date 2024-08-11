! Define the subroutine
subroutine bmf_splitwrite
       print *, '*****************************************************'
       print *, 'WARNING: bmf_splitwrite has been replaced by         '
       print *, ' bmf_splitwrite2 with an additional first argument   '
       print *, ' first argument should be RPN_COMM_split             '
       print *, '*****************************************************'
       stop
end subroutine bmf_splitwrite

! Main program to test the subroutine
program test_bmf_splitwrite
  call bmf_splitwrite
end program test_bmf_splitwrite