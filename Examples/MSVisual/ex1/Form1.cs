using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ex1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            nudVarCnt.Value = 1;
        }

        private void btStart_Click(object sender, EventArgs e)
        {

        }

        private void btContinue_Click(object sender, EventArgs e)
        {

        }

        private void btStop_Click(object sender, EventArgs e)
        {

        }

        private void btPause_Click(object sender, EventArgs e)
        {

        }

        private void nudVarCnt_ValueChanged(object sender, EventArgs e)
        {
            int colCnt = Convert.ToInt32(nudVarCnt.Value) + 1;

            while(dgvInput.Columns.Count > colCnt)
            {
                dgvInput.Columns.Remove("{" + Convert.ToString(dgvInput.Columns.Count-2) + "}");
            }

            while (dgvInput.Columns.Count < colCnt)
            {
                int colID = dgvInput.Columns.Count - 1;
                DataGridViewColumn dgvc = new DataGridViewTextBoxColumn();
                dgvc.Name = "{" + Convert.ToString(colID) + "}";
                dgvInput.Columns.Insert(colID, dgvc);
            }
        }

        private void dgvInput_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
