//
//  AppUtils.h
//
//  Created by dyf on 16/6/7.
//  Copyright © 2016年 dyf. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//

#import <Cocoa/Cocoa.h>

// AppChooseResponseBlock
typedef void (^AppChooseResponseBlock)(NSString *path);

// AppGetCertsResponseBlock
typedef void (^AppGetCertsResponseBlock)(NSMutableArray *certs);

@interface AppUtils : NSObject

/**
 *  打开Finder，选择文件或目录
 *
 *  @param canChooseFiles       是否能选择文件
 *  @param canChooseDirectories 是否能选择目录
 *  @param fileTypes            文件类型
 *  @param handler              完成回调
 */
- (void)openFinder:(BOOL)canChooseFiles chooseDirectories:(BOOL)canChooseDirectories allowedFileTypes:(NSArray<NSString *> *)fileTypes completionHandler:(AppChooseResponseBlock)handler;

/**
 *  打开Finder，选择文件或目录
 *
 *  @param canChooseFiles       是否能选择文件
 *  @param canChooseDirectories 是否能选择目录
 *  @param canCreateDirectories 是否能创建目录
 *  @param fileTypes            文件类型
 *  @param handler              完成回调
 */
- (void)openFinder:(BOOL)canChooseFiles chooseDirectories:(BOOL)canChooseDirectories canCreateDirectories:(BOOL)canCreateDirectories allowedFileTypes:(NSArray<NSString *> *)fileTypes completionHandler:(AppChooseResponseBlock)handler;

/**
 *  展示对话框
 *
 *  @param window
 *  @param style        样式
 *  @param title        标题
 *  @param message      信息
 *  @param buttonTitles 按钮标题
 *  @param handler
 *
 *  @return
 */
+ (NSAlert *)showAlert:(NSWindow *)window style:(NSAlertStyle)style title:(NSString *)title message:(NSString *)message buttonTitles:(NSArray *)buttonTitles completionHandler:(void (^)(NSInteger returnCode))handler;

/**
 *  本地存储
 *
 *  @param value
 *  @param key
 */
+ (void)localStore:(id)value forKey:(NSString *)key;

/**
 *  本地读取
 *
 *  @param key
 *
 *  @return
 */
+ (id)localRead:(NSString *)key;

/**
 *  设置按钮字体颜色
 *
 *  @param button 按钮
 *  @param color  RGB颜色
 */
+ (void)setTextColorForButton:(NSButton *)button color:(NSColor *)color;

@end
