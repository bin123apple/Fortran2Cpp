program main
  character (len=40) c
  c = "Hello, &
         world!" 
  if (c.ne."Hello, world!") STOP 1
end program main