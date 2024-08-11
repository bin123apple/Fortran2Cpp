program testSetprob
  call setprob
  print *, "Test passed."
end program testSetprob

subroutine setprob
  implicit double precision (a-h,o-z)
  return
end