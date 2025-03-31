//
//  crystalmanager.h
//  crystaldb
//
//  Created by Krisna Pranav on 31/03/25.
//

#import <UIKit/UIKit.h>

@protocol CrystalDB;
NS_ASSUME_NONNULL_BEGIN

@interface CrystalManager : NSObject

@property (readonly, nonatomic, copy) NSString *dbName;

@property (nonatomic, assign) BOOL isDebug;

@property (nonatomic, assign) BOOL isBindToObject;

+ (nonnull instancetype)defaultCrystalDB;

- (nonnull instancetype)initWithName:(nullable NSString*)dbName __attribute__((nonnull));

- (nonnull instancetype)initWithObject:(nullable id)object __attribute__((nonnull));

- (BOOL)addOrUpdateObject:(nonnull id<CrystalDB>)object;

@end

@end
