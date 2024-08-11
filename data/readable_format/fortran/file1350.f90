program zutos
   implicit none
   character(len=232) :: a
   character(:), allocatable :: b
   open(unit=10, file='output.txt', status='replace')
   
   a = "cono"//repeat(" ", 150)
   write(10, *) "a============"//new_line("a")//a//"fin"
   write(10, *) "trim(a)============"//new_line("a")//trim(a)//"fin"
   b = trim(a)
   write(10, *) "b=========="//new_line("a")//b//"fin"
   
   close(10)
end program