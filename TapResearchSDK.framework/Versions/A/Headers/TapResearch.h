//
//  TapResearch.h
//  TapResearchSDK
//
//  Copyright (c) 2015 TapResearch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

@class TRPlacement;

typedef NS_OPTIONS(NSInteger, TRPayoutType) {
    TRPayoutEventProfileComcplete=0,
    TRPayoutDidntQualify = 1,
    TRPayoutEventBonusPayout = 2,
    TRPayoutEventCampaignComplete = 3
};

@protocol TapResearchRewardsDelegate;
@protocol TapResearchSurveyDelegate;

/**
 Main interface for you to communicate with the TapResearch service.
 */
@interface TapResearch : NSObject

/**
 @method: initWithApiToken:delegate:
 @abstract: Initialize TapResearch with your apiToken and callback handler.

 @param: apiToken Your app's unique identifier.
 @param: delegate: The class that will implement the TapResearchDelegate protocol.
 */
+ (void)initWithApiToken:(NSString *)apiToken delegate:(id<TapResearchRewardsDelegate>)delegate;

+ (void)setUniqueUserIdentifier:(NSString *)userIdentifier;

+ (void)initPlacementWithIdentifier:(NSString *)placementIdentifier block:(void(^)(TRPlacement *placement))block;
/**
 @method: setNavigationBarColor
 @abstract: Set the survey wall navigation bar color
 @param: color: The navigation bar color
 */
+ (void)setNavigationBarColor:(UIColor *)color;

/**
 @method: setNavigationBarText
 @abstract: Set the survey wall navigation bar title
 @param: text: Navigation bar title
 */
+ (void)setNavigationBarText:(NSString *)text;

/**
 @method: setNavigationBarTextColor
 @abstract: Set the navigation bar text color
 @param: color: Navigation bar text color
 */
+ (void)setNavigationBarTextColor:(UIColor *)color;

+ (void)initWithApiToken:(NSString *)apiToken developmentPlatform:(NSString *)developmentPlatform developmentPlatformVersion:(NSString *)developmentPlatformVersion delegate:(id<TapResearchRewardsDelegate>)delegate;

@end

@protocol TapResearchRewardsDelegate <NSObject>

/**
 @method: tapResearchDidReceiveRewardWithQuantity:transactionIdentifier:currenyName:payoutEvent
 @abstract: Notifies the delegate that a user has earned an in-app reward.
 
 @param: quantity: Rewards quantity
 @param: transactionIdentifier: Rewards unique transaction identifier
 @param: currencyName: Currency name, depends on the payoutEvent
 @param: payoutEvent: Payout event type
 @param: placementIdentifier: The offer identifier
 */
- (void)tapResearchDidReceiveRewardWithQuantity:(NSInteger)quantity transactionIdentifier:(NSString *)transactionIdentifier
                                   currencyName:(NSString *)currencyName payoutEvent:(NSInteger)payoutEvent placementIdentifier:(NSString *)placementIdentifier;

@end

@protocol TapResearchSurveyDelegate <NSObject>

@optional

/**
 @method: tapResearchSurveyModalOpened
 @abstract: Notifies the delegate when a user opens the survey modal.
 
 @param: placement: Placement identifier
 */
- (void)tapResearchSurveyModalOpenedWithPlacement:(TRPlacement *)placement;

/**
 @method: tapResearchSurveyModalDismissed
 @abstract: Notifies the delegate when a user dismisses the survey modal.
 
 @param: placement: Placement identifier
 */
- (void)tapResearchSurveyModalDismissedWithPlacement:(TRPlacement *)placement;


@end

