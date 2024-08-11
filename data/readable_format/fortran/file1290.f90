subroutine s()
  print *, 's called'
end subroutine s

subroutine t()
  call s()
end subroutine t

program main
  call s()
  call t()
end program main