// pages/game_count/index.js
const db=wx.cloud.database()
Page({

  /**
   * 页面的初始数据
   */
  data: {
    rnd:''
  },
  game_countinput:function (e) {
    this.setData({
      rnd:e.detail.value
    })
  },
  jumpPage:function(){
    db.collection("roundcount").add({
      data:{
        rnd:this.data.rnd,
        _id:1
      }
    }).then(res=>{
      wx.showToast({
        title: '设置成功',
        mask:true,
        icon:'success'
      })
      })
   console.log("account: " + this.data.rnd);
    wx.navigateTo({
      url: '/pages/game_set/index'
    })
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