program test_interface_setprob
      implicit none
      double precision rhol, cl, rhor, cr
      double precision rhol_com, cl_com, rhor_com, cr_com
      common /comaux/ rhol_com, cl_com, rhor_com, cr_com

      rhol = 1.0
      cl = 2.0
      rhor = 3.0
      cr = 4.0

      call interface_setprob(rhol, cl, rhor, cr)

      print *, "Testing interface_setprob..."
      if (rhol_com .eq. rhol) then
         print *, "rhol_com is correct."
      else
         print *, "Error: rhol_com is incorrect."
      endif

      if (cl_com .eq. cl) then
         print *, "cl_com is correct."
      else
         print *, "Error: cl_com is incorrect."
      endif

      if (rhor_com .eq. rhor) then
         print *, "rhor_com is correct."
      else
         print *, "Error: rhor_com is incorrect."
      endif

      if (cr_com .eq. cr) then
         print *, "cr_com is correct."
      else
         print *, "Error: cr_com is incorrect."
      endif

      stop
      end

      subroutine interface_setprob(rhol, cl, rhor, cr)
      implicit none
      double precision rhol, cl, rhor, cr
      double precision rhol_com, cl_com, rhor_com, cr_com
      common /comaux/ rhol_com, cl_com, rhor_com, cr_com

      rhol_com = rhol
      cl_com = cl
      rhor_com = rhor
      cr_com = cr

      return
      end