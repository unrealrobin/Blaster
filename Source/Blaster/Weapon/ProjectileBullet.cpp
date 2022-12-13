// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBullet.h"

#include "Blaster/Character/BlasterCharacter.h"
#include "Kismet/GameplayStatics.h"

void AProjectileBullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                              FVector NormalImpulse, const FHitResult& Hit)
{
	//Get Character Owner. Cast from the GetOwner() which returns an AACtor to a ACharacter class.
	//From the ACharacter class we can get a reference to that characters controller.
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
	if(OwnerCharacter)
	{
		AController* OwnerController = OwnerCharacter->Controller; //Owning controller who shot the projectile
		if(OwnerController)
		{
			//Apply Damage Built In Function
			UGameplayStatics::ApplyDamage(OtherActor, Damage, OwnerController, this, UDamageType::StaticClass());
		}
	}
	

	//we call this second because it calls destroy but we need some logic to run before it destroys the projectile.
	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
}
