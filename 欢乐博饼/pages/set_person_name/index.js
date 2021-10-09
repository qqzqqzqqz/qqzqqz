// pages/set_person_name/index.js
const db=wx.cloud.database()
const app = getApp()
Page({

  /**
   * 页面的初始数据
   */
  data: {
    username:'',
    count:0,
    cnt:1,
    list:[
      {
        id:1,
        title:'玩家一昵称:',
        name:''
      },
      {
        id:2,
        title:'玩家二昵称:',
        name:''
      },
      {
        id: 3,
        title: '玩家三昵称:',
        name:''
      },
      {
        id: 4,
        title: '玩家四昵称:',
        name:''
      }
    ],
  },
  nameinput:function (e) {
    this.setData({
      username:e.detail.value
    })
  },
  addinfo:function () {
    wx.showLoading({
      title: '加载中',
      mask:true
    })
    db.collection("userlist").add({
      data:{
        name:this.data.username
      }
    }).then(res=>{
      wx.hideLoading()
  })
},

  accomplish:function(){
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