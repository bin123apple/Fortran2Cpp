program main
  implicit none
  character(len=10) :: string
  character(len=5) :: substring
  
  ! Initialize the string
  string = "A123456789"
  
  ! Extract the substring
  substring(1:5) = string(2:6)
  
  ! Test output
  print *, "Substring: ", substring
end program main