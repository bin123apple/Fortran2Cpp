! test_movie.f90
program test_movie
  external movie

  call movie
  print *, "Test passed: subroutine 'movie' executed successfully."

end program test_movie

subroutine movie
  ! This is the original subroutine which does nothing
  return
end subroutine movie