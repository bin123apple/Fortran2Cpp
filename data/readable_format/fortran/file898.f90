module no_endmodule_m1
  integer :: a = 5
end module

module no_endmodule_m2
  integer :: b = 10
end

program test
  use no_endmodule_m1
  use no_endmodule_m2
  if (a == 5 .and. b == 10) then
    print *, "Test Passed"
  else
    print *, "Test Failed"
  end if
end program