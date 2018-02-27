//
//  TRPlacement.h
//  TapResearchSDK
//
//  Created by Ilan Caspi on 1/22/18.
//  Copyright © 2018 TapResearch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TapResearchSDK.h"

@interface TRPlacement : NSObject

@property (nonatomic, copy) NSString *placementIdentifier;
@property (nonatomic, copy) NSString *currencyName;
@property (nonatomic, copy) NSString *placementErrorMessage;
@property (nonatomic, assign) BOOL isSurveyWallAvailable;
@property (nonatomic, assign) NSInteger placementCode;
@property (nonatomic, assign) NSInteger maxPayoutInCurrency;
@property (nonatomic, assign) NSInteger minPayoutInCurrency;
@property (nonatomic, assign) NSInteger maxSurveyLength;
@property (nonatomic, assign) NSInteger minSurveyLength;

- (void)showSurveyWallWithDelegate:(id<TapResearchSurveyDelegate>)surveyDelegate;

@end
