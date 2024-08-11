subroutine sub(N,u)
      integer N
      double precision u(-N:N,-N:N)

      u(-N,N)=0d0
      return
end

program bug
      integer N
      double precision a(-10:10,-10:10)
      data a/441*1d0/
      N=10
      call sub(N,a)
      if (a(-N,N) .ne. 0d0) then
         print *, 'Test failed: a(-N,N) is not 0d0'
         call abort
      else
         print *, 'Test passed: a(-N,N) is 0d0'
      end if
end program bug