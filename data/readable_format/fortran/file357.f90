program main
      character*2 a
      character*4 b
      character*6 c
      parameter (a="12")
      parameter (b = a)

      write (c,'("#",A,"#")') b
      if (c .ne. '#12  #') then
         print *, 'Aborting...'
         call abort
      else
         print *, 'All tests passed successfully.'
      end if
end program main