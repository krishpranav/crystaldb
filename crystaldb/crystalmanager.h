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

@property (readonly,nonatomic,copy) NSString *dbName;

@property (nonatomic,assign) BOOL isDebug;

@property (nonatomic,assign) BOOL isBindToObject;

+ (nonnull instancetype)defaultCrystalDB;

- (nonnull instancetype)initWithName:(nullable NSString *)dbName __attribute__((nonnull));

- (nonnull instancetype)initWithObject:(nullable id)object __attribute__((nonnull));

- (BOOL)addOrUpdateObject:(nonnull id<CrystalDB>)object;

- (BOOL)addOrIgnoreObject:(nonnull id<CrystalDB>)object;

- (BOOL)addOrUpdateWithClass:(nonnull Class)objectClass withDict:(nonnull NSDictionary *)dictionary;

- (nullable id)queryWithClass:(nonnull Class)objectClass onPrimary:(nonnull id)primaryValue;

- (nonnull NSArray *)queryWithClass:(nonnull Class)objectClass condition:(nullable NSString *)condition;

- (nonnull NSArray *)queryWithClass:(nonnull Class)objectClass conditions:(nullable NSString *)conditionFormat,...;

- (nonnull NSArray *)queryWithClass:(nonnull Class)objectClass where:(nullable NSString *)where orderBy:(nullable NSString *)orderBy limit:(nullable NSString *)limit;

- (NSInteger)queryCount:(nonnull Class)objectClass;

- (NSInteger)queryUpdateTime:(nonnull id)object;

- (NSInteger)queryCreateTime:(nonnull id)object;

- (BOOL)deleteObject:(nonnull id)object;

- (BOOL)deleteClass:(nonnull Class)objectClass where:(nullable NSString *)where;

- (BOOL)updateObject:(nonnull id)object;

- (BOOL)dropAll;

- (BOOL)dropClass:(nonnull Class)objectClass;

- (BOOL)clearRedundancy;

- (void)inTransaction:(nonnull void (^)( BOOL * _Nonnull rollback))block;

- (nullable NSString *)objectID:(nullable id)object;

- (nullable NSString *)objectNotificationName:(nullable id)object;

@end
NS_ASSUME_NONNULL_END

@protocol CrystalDB <NSObject>
@optional

+ (BOOL)CrystalDBObjectIsHasSuperClass;

+ (nonnull NSString *)CrystalDBName;

+ (nonnull NSString *)CrystalDBPrimaryKey;

+ (nonnull NSArray<NSString *> *)CrystDBWhitelistProperties;

+ (nonnull NSArray<NSString *> *)CrystDBBlacklistProperties;

@end
