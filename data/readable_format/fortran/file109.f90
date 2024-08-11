module FLAGS
  character(len=5) :: Encodings
  character :: at, dev
  equivalence ( encodings(1:1),at ), ( encodings(2:2),dev)
end module FLAGS

program testFLAGS
  use FLAGS
  implicit none

  Encodings = "ABCDE"
  at = 'Z'
  dev = 'Y'

  if (Encodings /= "ZYCDE") then
    print *, "Test failed: Encodings was not correctly updated."
  else
    print *, "Test passed: Encodings correctly updated to ZYCDE."
  end if

  ! Reset and perform another test
  Encodings = "12345"
  at = '9'
  dev = '8'

  if (Encodings /= "98345") then
    print *, "Test failed: Encodings was not correctly updated on second test."
  else
    print *, "Test passed: Encodings correctly updated to 98345 on second test."
  end if
end program testFLAGS