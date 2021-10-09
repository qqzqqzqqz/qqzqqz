// pages/index3/index.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    ScreenBrightness: '',
  },
  changeScreenLight:function(e){  
    var that = this;  
    //获得滑动拉杆值 ，改变屏幕亮度
    wx.setScreenBrightness({  
      value: parseFloat(e.detail.value).toFixed(1)  
    })  
    //获得屏幕亮度
    wx.getScreenBrightness({  
      success: function(res) {  
        that.setData({  
          ScreenBrightness: res.value  
        })  
      }  
    })  
  } ,
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    var that = this
    // 获取屏幕亮度
    wx.getScreenBrightness({
      success: function (res) {
        that.setData({
          ScreenBrightness: res.value
        })
      }
    })
    //设置屏幕亮度
    wx.setScreenBrightness({
      value: 1,    //屏幕亮度值，范围 0~100，0 最暗，1 最亮
    })
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