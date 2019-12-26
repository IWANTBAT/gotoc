/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package 分析协议;


public class 分析协议 {

    public static void main(String[] args) {
        String str = "98eecb6d6fec487d2e5da24108004500002b512c40003906c1cb6f13fdb0c0a80169005020fb26809e56a6eb7cfd501803e938fd000000033a";
        String str_tmac = str.substring(0, 12);//str_tmac:mac目的地址
        String str_fmac = str.substring(12, 24);//str_fmac:mac源地址
        System.out.println("MAC源地址："+str_fmac);
        System.out.println("MAC目的地址："+str_tmac);
         String str_smac = str.substring(28);//mac数据部分
        System.out.println("mac数据部分："+str_smac);
    
        String str_lmac = str.substring(24, 28);
        System.out.println(str_lmac);
        //System.out.println(str_lmac);
        //System.out.println("str_lmac"+str_lmac);
        zhuanshij z = new zhuanshij();
        //网络层类型
        
        if(str_lmac == "0800"){
            System.out.println("IP协议");
        }
        String str_bip = str.substring(28, 29);
        int bip =(int) z.zhuanshi(str_bip);//ip版本号
        
        System.out.println("ip版本号"+bip);
        String str_lenip = str.substring(29, 30);
        //System.out.println("ipbajdhhds"+str_lenip);
        int lip =(int) z.zhuanshi(str_lenip);//ip首部长度
        lip = lip*4;
        System.out.println("ip首部长度:"+lip);
        String str_zlip = str.substring(32, 36);
        int zlip =(int) z.zhuanshi(str_zlip);//ip总长度
        //System.out.println("jdfhguhashg"+str_zlip);
        System.out.println("ip总长度："+zlip);
        String str_tip = str.substring(52, 60);//ip源地址
        System.out.println("ip源地址："+str_tip);
        String str_fip = str.substring(60, 68);//ip目的地址
        System.out.println("ip目的地址："+str_fip);
        String str_sip = str.substring(lip+28);//ip数据部分
        System.out.println("ip数据部分： "+str_sip);
        String str_YS = str.substring(46, 48);
        //System.out.println(str_YS);
        int lsh = (int)z.zhuanshi(str_YS);//运输层协议
        //System.out.println("运输层：：："+lsh);
        if(lsh == 17){
            System.out.println("运输层协议为UDP");
            String str_tudp = str.substring(lip+28, lip+32);//UDP源地址
            String str_fudp = str.substring(lip+32, lip +36);//UDP目的地址 
            String str_fdk = str.substring(lip+44, lip+48);
            int ydk = (int)z.zhuanshi(str_fdk);//UDP源端口
            String str_tdk = str.substring(lip+48, lip+52);
            int mdk = (int)z.zhuanshi(str_tdk);//UDP目的端口
            String str_sudp = str.substring(lip+52,lip+56);
            int sudp = (int)z.zhuanshi(str_sudp);//UDP首部长度
            String str_sjudp = str.substring(lip+sudp+28);//UDP数据部分
        }
        else if(lsh == 6){
            System.out.println("运输层协议为TCP");
            String str_tdtcp = str.substring(lip+28, lip+32);
            int ytd = (int)z.zhuanshi(str_tdtcp);//TCP源端口
            System.out.println("TCP源端口为："+ytd);
            String str_fdtcp = str.substring(lip+32, lip+36);
            int ftd = (int)z.zhuanshi(str_fdtcp);//TCP目的端口
            System.out.println("TCP目的端口为："+ftd);
        }            
    }
}



