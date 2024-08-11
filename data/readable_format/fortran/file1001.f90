program testSubroutines
  implicit none

  call s1
  print *, 's1 called successfully.'

  call s2
  print *, 's2 called successfully.'

end program testSubroutines

subroutine s1
  implicit none
end subroutine s1

subroutine s2
  implicit none
end subroutine s2