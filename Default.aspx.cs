using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

public partial class _Default : System.Web.UI.Page
{
    SqlConnection myConnection= new SqlConnection(System.Web.Configuration.WebConfigurationManager.ConnectionStrings["Con"].ConnectionString.ToString());
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            SelectInfo();
        }
     }
    protected void Open()
    {
        myConnection.Open();
    }
    protected void SelectInfo()
    {
        Open();
        SqlCommand myCommand = new SqlCommand("select * from student", myConnection);
        SqlDataAdapter Adapter = new SqlDataAdapter();
        Adapter.SelectCommand = myCommand;
        DataSet myDs = new DataSet();
        Adapter.Fill(myDs);
        Response.Write("<h3>学生表</h3>");
        Response.Write("<table border=1 cellspacing=0 cellpadding=2>");
        DataTable myTable = myDs.Tables[0];
        Response.Write("<tr bgcolor=yellow>");
        foreach (DataColumn myColumn in myTable.Columns)
        {
            Response.Write("<td>" + myColumn.ColumnName + "</td>");
        }
        Response.Write("</tr>");
        foreach (DataRow myRow in myTable.Rows)
        {
            Response.Write("<tr>");
            foreach (DataColumn myColumn in myTable.Columns)
            {
                Response.Write("<td>" + myRow[myColumn] + "</td>");
            }
            Response.Write("</tr>");
        }
        Response.Write("</table>");
        myConnection.Close();    
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        Open();
        string str = " insert into student values(211,'wangxiao','Web')";
        SqlCommand com = new SqlCommand(str,myConnection );
        com.ExecuteNonQuery();
        myConnection.Close();
        SelectInfo();

    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        Open();
        string str = "update student set course = 'C#'where sno =2";
        SqlCommand com = new SqlCommand(str, myConnection);
        com.ExecuteNonQuery();
        myConnection.Close();
        SelectInfo();
    }
    protected void Button3_Click(object sender, EventArgs e)
    {
        Open();
        string str = "delete from  student where sno=1";
        SqlCommand com = new SqlCommand(str, myConnection);
        com.ExecuteNonQuery();
        myConnection.Close();
        SelectInfo();
    }
}