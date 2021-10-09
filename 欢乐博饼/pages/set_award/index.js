// pages/set_award/index.js
const db=wx.cloud.database()
Page({

  /**
   * 页面的初始数据
   */
  data: {
    awardname:''
  },
  awardinput1:function (e) {
    this.setData({
      awardname:e.detail.value
    })
  },
  addinfo1:function () {
    wx.showLoading({
      title: '加载中',
      mask:true
    })
    db.collection("prizelist").add({
      data:{
        zhuangyuan:this.data.awardname
      }
    }).then(res=>{
      wx.hideLoading()
      })
   console.log("account: " + this.data.awardname);
  },
  awardinput2:function (e) {
    this.setData({
      awardname:e.detail.value
    })
  },
  addinfo2:function () {
    wx.showLoading({
      title: '加载中',
      mask:true
    })
    db.collection("prizelist").add({
      data:{
        bangyan:this.data.awardname
      }
    }).then(res=>{
      wx.hideLoading()
      })
   console.log("account: " + this.data.awardname);
  },
  awardinput3:function (e) {
    this.setData({
      awardname:e.detail.value
    })
  },
  addinfo3:function () {
    wx.showLoading({
      title: '加载中',
      mask:true
    })
    db.collection("prizelist").add({
      data:{
        tanhua:this.data.awardname
      }
    }).then(res=>{
      wx.hideLoading()
      })
   console.log("account: " + this.data.awardname);
  },
  awardinput4:function (e) {
    this.setData({
      awardname:e.detail.value
    })
  },
  addinfo4:function () {
    wx.showLoading({
      title: '加载中',
      mask:true
    })
    db.collection("prizelist").add({
      data:{
        jinshi:this.data.awardname
      }
    }).then(res=>{
      wx.hideLoading()
      })
   console.log("account: " + this.data.awardname);
  },
  awardinput5:function (e) {
    this.setData({
      awardname:e.detail.value
    })
  },
  addinfo5:function () {
    wx.showLoading({
      title: '加载中',
      mask:true
    })
    db.collection("prizelist").add({
      data:{
        juren:this.data.awardname
      }
    }).then(res=>{
      wx.hideLoading()
      })
   console.log("account: " + this.data.awardname);
  },
  awardinput6:function (e) {
    this.setData({
      awardname:e.detail.value
    })
  },
  addinfo6:function () {
    wx.showLoading({
      title: '加载中',
      mask:true
    })
    db.collection("prizelist").add({
      data:{
        xiucai:this.data.awardname
      }
    }).then(res=>{
      wx.hideLoading()
      })
   console.log("account: " + this.data.awardname);
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