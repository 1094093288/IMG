class c223 {
   public static void main(String[] var0) throws Exception {
      System.out.print("Paving your way.");
      pave("");
   }

   public static void pave(String var0) throws Exception {
      var0 = var0 + "T";
      System.out.print(".");
      Thread.sleep(3600000L);
      c626.pave(var0);
   }
}
