// pages/index1/index.js
const db=wx.cloud.database()

function rand () {
  return Math.round(Math.random()*6)
}
Page({

  /**
   * 页面的初始数据
   */
  data: {
    user:'',
    cnt:'',
    value:['1','2','3','4','5','6'],
    value2:'',
    round:0,
    temp:0,
    count:0,
    cnt1:0
  },
  start:function() {
    var val1=['','','','','',''];
    var val2=[0,0,0,0,0,0];
    if(this.data.round==0){
      db.collection("roundcount").get({
        success:res=>{
          this.setData({
            round:res.data[0].rnd
          })
        //  console.log(this.data.round)
        }
      })
      db.collection("totaluser").get({
        success:res=>{
          this.setData({
            temp:res.data[0].count,
            cnt1:res.data[0].count
          })
          console.log(res)
          // console.log(this.data.cnt1)
        }
      })
    }
    var round=this.data.round;
    round--
    var count1=this.data.temp;
    count1++
    this.setData({
      temp:count1
    })
   // console.log(this.data.temp)
    this.setData({
      round:round
    })
    db.collection('userlist').get({
      success: res => {
        this.setData({
          user: res.data,
        })
        console.log(this.data.user)
      }
    })
    for(var i=0;i<6;i++){
      val1[i] = rand();
      while(1)
      if(val1[i] == '0'){
       val1[i] = rand();
    }
      else break;
    }
    this.setData({  
      value:val1
  })
    for(var i=0;i<6;i++){
      val2[val1[i]]++;
    }
    if(val2[4]==1){
      this.setData({  
        value2:'一秀'
       })
    } 
    if(val2[4]==2){
      this.setData({  
        value2:'二举'
      })
    }
    if(val2[4]==3){
      this.setData({  
        value2:'三红'
       })
    }
    if(val2[4]>=4||val2[1]>=5||val2[2]>=5||val2[3]>=5||val2[5]>=5||val2[6]>=5){
      this.setData({  
        value2:'状元！'
       })
    }
    if(val2[1]==1&&val2[2]==1&&val2[3]==1&&val2[4]==1&&val2[5]==1&&val2[6]==1){
      this.setData({  
        value2:'对堂'
       })
    }
    if(val2[1]==4||val2[2]==4||val2[3]==4||val2[5]==4||val2[6]==4){
      this.setData({  
        value2:'四进'
       })
    }
    else if(val2[4]==0){
      this.setData({  
        value2:'再接再厉'
       })
    }
    round--
    round:round
    wx.showToast({
      title: this.data.value2,
      icon: 'none',
      duration: 1000,
      mask:true
  })
  console.log(val1)
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})